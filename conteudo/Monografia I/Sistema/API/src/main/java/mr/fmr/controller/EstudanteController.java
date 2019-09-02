package mr.fmr.controller;

import mr.fmr.model.Estudante;
import mr.fmr.service.EstudanteService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping
public class EstudanteController {

    final String BASE_URL = "/estudante";

    @Autowired
    private EstudanteService estudanteService;

    @PutMapping(value = BASE_URL)
    public Estudante update(@RequestBody Estudante estudante) {
        return estudanteService.save(estudante);
    }
}
