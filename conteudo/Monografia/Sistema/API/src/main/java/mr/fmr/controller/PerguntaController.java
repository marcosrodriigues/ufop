package mr.fmr.controller;

import mr.fmr.model.Pergunta;
import mr.fmr.service.PerguntaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping
public class PerguntaController {

    final String BASE_URL = "/pergunta";

    @Autowired
    private PerguntaService service;

    @GetMapping(value = BASE_URL)
    public List<Pergunta> findAll() {
        return service.findAll();
    }

    @GetMapping(value = BASE_URL + "/{id}")
    public Pergunta findOne(@RequestParam("id") Integer id) {
        return service.findOne(id);
    }
}
