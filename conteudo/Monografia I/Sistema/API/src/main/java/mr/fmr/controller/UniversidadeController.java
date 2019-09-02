package mr.fmr.controller;

import mr.fmr.model.Universidade;
import mr.fmr.service.UniversidadeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping
public class UniversidadeController {

    final String BASE_URL = "/universidade";

    @Autowired
    private UniversidadeService service;

    @PostMapping(value = BASE_URL)
    public Universidade save(@RequestBody Universidade universidade) {
        return service.save(universidade);
    }

    @GetMapping(value = BASE_URL)
    public List<Universidade> findAll() {
        return service.findAll();
    }
}
