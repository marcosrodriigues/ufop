package mr.fmr.controller;

import mr.fmr.model.Estudante;
import mr.fmr.model.MoradorRepublica;
import mr.fmr.model.Republica;
import mr.fmr.model.User;
import mr.fmr.service.MoradorRepublicaService;
import mr.fmr.service.RepublicaService;
import mr.fmr.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.security.Principal;
import java.util.List;

@RestController
@RequestMapping
public class RepublicaController {

    final String BASE_URL = "/republica";

    @Autowired
    private RepublicaService service;
    @Autowired
    private UserService userService;
    @Autowired
    private MoradorRepublicaService moradorService;

    @PutMapping(value = BASE_URL)
    public Republica update(@RequestBody Republica republica) {
        return service.save(republica);
    }

    @GetMapping(value = BASE_URL)
    public List<Republica> getAll() {
        return service.findAll();
    }

    @GetMapping(value = BASE_URL + "/byUf/{uf}")
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
        }

        return null;
    }

    @GetMapping(value = BASE_URL + "/pendentes")
    public List<Estudante> findPendentes(Principal principal) {
        User me = userService.getUserFromPrincipal(principal);

        if (me instanceof Republica) {
            Republica rep = (Republica) me;
            return service.findPendentes(rep);
        }

        return null;
    }

    @PostMapping(value = BASE_URL + "/aprovar")
    public MoradorRepublica aprovar(Principal principal, @RequestBody Estudante estudante) {
        User user = userService.getUserFromPrincipal(principal);

        if (user instanceof  Republica) {
            Republica me = (Republica) user;
            return moradorService.aprovar(estudante, me);
        }

        return null;
    }

    @PostMapping(value = BASE_URL + "/recusar")
    public void recusar(Principal principal, @RequestBody Estudante estudante) {
        User user = userService.getUserFromPrincipal(principal);

        if (user instanceof  Republica) {
            Republica me = (Republica) user;
            moradorService.recusar(estudante, me);
            return;
        }
    }

}
