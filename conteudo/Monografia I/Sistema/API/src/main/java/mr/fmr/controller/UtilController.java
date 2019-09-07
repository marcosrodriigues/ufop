package mr.fmr.controller;

import mr.fmr.service.EnderecoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping
public class UtilController {

    final String BASE_URL = "/util";

    @Autowired
    private EnderecoService enderecoService;

    @GetMapping(value = BASE_URL + "/getCityWhereHasRepublic/{uf}")
    public List<String> getCityWhereHasRepublic(@PathVariable("uf") String uf) {
        return enderecoService.getCityWhereHasRepublic(uf);
    }

    @GetMapping(value = BASE_URL + "/getUfWhereHasRepublic")
    public List<String> getUfWhereHasRepublic() {
        return enderecoService.getUfWhereHasRepublic();
    }
}
