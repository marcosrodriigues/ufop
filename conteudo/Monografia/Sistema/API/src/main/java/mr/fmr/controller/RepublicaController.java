package mr.fmr.controller;

import mr.fmr.CaraterRepublica;
import mr.fmr.exception.MyBadRequestException;
import mr.fmr.exception.MyUnauthorizedException;
import mr.fmr.model.Estudante;
import mr.fmr.model.MoradorRepublica;
import mr.fmr.model.Republica;
import mr.fmr.model.User;
import mr.fmr.payload.RepublicaDetalhes;
import mr.fmr.payload.RepublicaPorPersonalidadePayload;
import mr.fmr.service.MoradorRepublicaService;
import mr.fmr.service.RecomendacaoService;
import mr.fmr.service.RepublicaService;
import mr.fmr.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.security.Principal;
import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping
public class RepublicaController {

    final String BASE_URL = "/republica";

    @Autowired
    private RepublicaService service;
    @Autowired
    private RecomendacaoService recomendacaoService;
    @Autowired
    private UserService userService;
    @Autowired
    private MoradorRepublicaService moradorService;

    @PutMapping(value = BASE_URL)
    public Republica update(@RequestBody Republica republica) {
        return service.save(republica);
    }

    @GetMapping(value = BASE_URL + "/{id}")
    public RepublicaDetalhes findOne(@PathVariable("id") Integer id) {
        Republica rep = service.findOne(id);

        return new RepublicaDetalhes(rep);
    }


    @GetMapping(value = BASE_URL)
    public List<Republica> getAll() {
        return service.findAll();
    }

    @GetMapping(value = BASE_URL + "/city/{city}")
    public List<RepublicaPorPersonalidadePayload> getByCity(Principal principal, @PathVariable("city") String city) {
        User me = userService.getUserFromPrincipal(principal);
        if (me.getPerfil().getPersonalidade() == null) {
            throw new MyBadRequestException("Faça o Teste de Personalidade antes de buscar a república");
        }

        List<Republica> republicasNaCidade = service.findByCity(city);

        List<RepublicaPorPersonalidadePayload> republicas = new ArrayList<>();
        RepublicaPorPersonalidadePayload payloadRep;
        for (Republica rep :republicasNaCidade) {
            if (rep.getPerfil().getPersonalidade() == null) continue;

            payloadRep = new RepublicaPorPersonalidadePayload(rep);
            int sumPersonality = recomendacaoService.somaPersonalidade(rep.getPerfil().getPersonalidade());
            int distanciaGeral = recomendacaoService.calculaDistanciaGeral(me, rep);
            payloadRep.setDistanciaGeral(distanciaGeral);
            payloadRep.setSomaPersonalidade(sumPersonality);
            republicas.add(payloadRep);

        }

        return recomendacaoService.ordenar(republicas);
    }

    @GetMapping(value = BASE_URL + "/uf/{uf}")
    public List<Republica> getByUf(@PathVariable("uf") String uf) {
        return service.findByUf(uf);
    }

    @GetMapping(value = BASE_URL + "/{uf}/{city}")
    public List<Republica> getByUfAndCity(@PathVariable("uf") String uf, @PathVariable("city") String city) {
        return service.findByUfAndCity(uf, city);
    }

    @GetMapping(value = BASE_URL + "/moradores")
    public List<Estudante> findMoradores(Principal principal) {
        User me = userService.getUserFromPrincipal(principal);

        if (me instanceof Republica) {
            Republica rep = (Republica) me;
            return service.findMoradores(rep);
        } else if (me instanceof Estudante) {
            Estudante est = (Estudante) me;
            return service.findMoradores(est.getMoradorRepublica().getRepublica());
        }

        return null;
    }

    @GetMapping(value = BASE_URL + "/pendentes")
    public List<Estudante> findPendentes(Principal principal) {
        User me = userService.getUserFromPrincipal(principal);

        if (me instanceof Republica) {
            Republica rep = (Republica) me;
            return service.findPendentes(rep);
        } else if (me instanceof Estudante) {
            Estudante est = (Estudante) me;
            return service.findPendentes(est.getMoradorRepublica().getRepublica());
        }

        return null;
    }

    @PostMapping(value = BASE_URL + "/aprovar")
    public MoradorRepublica aprovar(Principal principal, @RequestBody Estudante estudante) {
        User user = userService.getUserFromPrincipal(principal);

        if (user instanceof  Republica) {
            Republica me = (Republica) user;
            return moradorService.aprovar(estudante, me);
        } else if (user instanceof Estudante) {
            Estudante me = (Estudante) user;
            return moradorService.aprovar(estudante, me.getMoradorRepublica().getRepublica());
        }

        return null;
    }

    @PostMapping(value = BASE_URL + "/recusar")
    public void recusar(Principal principal, @RequestBody Estudante estudante) {
        User user = userService.getUserFromPrincipal(principal);

        if (user instanceof  Republica) {
            Republica me = (Republica) user;
            moradorService.recusar(estudante, me);
        } else if (user instanceof Estudante) {
            Estudante me = (Estudante) user;
            moradorService.recusar(estudante, me.getMoradorRepublica().getRepublica());
        }
    }

    @PostMapping(value = BASE_URL + "/personalidade")
    public Republica calcularPersonalidade(Principal principal, @RequestBody Republica republica) {
        User user = userService.getUserFromPrincipal(principal);

        if (user instanceof Estudante) {
            Estudante me = (Estudante) user;
            if (!me.getMoradorRepublica().getRepublica().equals(republica))
                throw new MyUnauthorizedException("Usuário não pode executar esta tarefa!");

            return service.createPersonality(republica);
        }

        Republica me = (Republica) user;

        return service.createPersonality(me);
    }

    @GetMapping(value = BASE_URL + "/search/{cidade}/{carater}")
    public List<RepublicaPorPersonalidadePayload> findBySearch(Principal principal, @PathVariable("cidade") String cidade, @PathVariable("carater") String carater) {
        User me = new User();
        if (principal != null) me = userService.getUserFromPrincipal(principal);

        List<Republica> republicas = service.findByCity(cidade);
        List<RepublicaPorPersonalidadePayload> retorno = new ArrayList<>();
        RepublicaPorPersonalidadePayload payload;
        int sumPersonality = 0, distanciaGeral = 0;
        for (Republica r : republicas) {
            if ("TODOS".equalsIgnoreCase(carater) || (r.getCarater() != null && r.getCarater().name().equalsIgnoreCase(carater))) {
                payload = new RepublicaPorPersonalidadePayload(r);

                if (r.getPerfil() == null || me.getPerfil() == null) {
                    sumPersonality = 0;
                    distanciaGeral = 0;
                } else {
                    sumPersonality = recomendacaoService.somaPersonalidade(r.getPerfil().getPersonalidade());
                    distanciaGeral = recomendacaoService.calculaDistanciaGeral(me, r);

                }

                payload.setDistanciaGeral(distanciaGeral);
                payload.setSomaPersonalidade(sumPersonality);

                retorno.add(payload);
            }
        }

        return recomendacaoService.ordenar(retorno);
    }
}

