package mr.fmr.controller;

import mr.fmr.model.Estudante;
import mr.fmr.model.MoradorRepublica;
import mr.fmr.model.Republica;
import mr.fmr.service.EstudanteService;
import mr.fmr.service.MoradorRepublicaService;
import mr.fmr.service.RepublicaService;
import mr.fmr.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.security.Principal;

@RestController
@RequestMapping
public class EstudanteController {

    final String BASE_URL = "/estudante";

    @Autowired
    private EstudanteService estudanteService;
    @Autowired
    private UserService userService;
    @Autowired
    private RepublicaService republicaService;
    @Autowired
    private MoradorRepublicaService moradorRepublicaService;


    @PutMapping(value = BASE_URL)
    public Estudante update(@RequestBody Estudante estudante) {
        return estudanteService.save(estudante);
    }

    @PostMapping(value = BASE_URL + "/vincular")
    public MoradorRepublica vincular(Principal principal, @RequestParam("id_republica") int id_republica) {
        Estudante estudante = (Estudante) userService.getUserFromPrincipal(principal);
        Republica republica = republicaService.findOne(id_republica);

        return moradorRepublicaService.vincular(estudante, republica);
    }

    @PostMapping(value = BASE_URL)
    public Estudante save(@RequestBody Estudante estudante) {
        return estudanteService.save(estudante);
    }

}
