package mr.fmr.controller;

import mr.fmr.model.Republica;
import mr.fmr.service.RepublicaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping
public class RepublicaController {

    final String BASE_URL = "/republica";

    @Autowired
    private RepublicaService service;

    @PutMapping(value = BASE_URL)
    public Republica update(@RequestBody Republica republica) {
        return service.save(republica);
    }
}
