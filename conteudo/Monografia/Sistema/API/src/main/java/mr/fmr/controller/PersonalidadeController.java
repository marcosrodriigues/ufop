package mr.fmr.controller;

import mr.fmr.model.Personalidade;
import mr.fmr.model.User;
import mr.fmr.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.security.Principal;

@RestController
@RequestMapping
public class PersonalidadeController {

    final String BASE_URL = "/personalidade";

    @Autowired
    private UserService userService;

    @GetMapping(value = BASE_URL)
    public Personalidade getPersonalidade(Principal principal) {
        User me = userService.getUserFromPrincipal(principal);
        if (me.getPerfil().getPersonalidade() == null) return null;

        return me.getPerfil().getPersonalidade() ;
    }
}
