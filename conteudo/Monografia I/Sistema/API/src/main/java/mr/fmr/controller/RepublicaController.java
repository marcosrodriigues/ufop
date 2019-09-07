package mr.fmr.controller;

import mr.fmr.model.Republica;
import mr.fmr.service.RepublicaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

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

}
