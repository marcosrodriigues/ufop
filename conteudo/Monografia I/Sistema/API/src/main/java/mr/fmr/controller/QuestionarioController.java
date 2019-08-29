package mr.fmr.controller;

import mr.fmr.model.Questionario;
import mr.fmr.service.QuestionarioService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping
public class QuestionarioController {

    final String BASE_URL = "/questionario";

    @Autowired
    private QuestionarioService service;

    @GetMapping(value = BASE_URL)
    public List<Questionario> findAll() {
        return service.findAll();
    }

    @GetMapping(value = BASE_URL + "/{id}")
    public Questionario findOne(@RequestParam("id") Integer id) {
        return service.findOne(id);
    }
}
