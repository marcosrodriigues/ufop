package mr.fmr.controller;

import mr.fmr.model.Inventario;
import mr.fmr.model.InventarioPerguntaResposta;
import mr.fmr.model.User;
import mr.fmr.service.InventarioPerguntaRespostaService;
import mr.fmr.service.PersonalidadeService;
import mr.fmr.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.security.Principal;
import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping
public class InventarioController {

    final String BASE_URL = "/inventario";

    @Autowired
    private InventarioPerguntaRespostaService perguntaRespostaService;
    @Autowired
    private UserService userService;

    @PostMapping(value = BASE_URL)
    public List<InventarioPerguntaResposta> saveAll(Principal principal, @RequestBody  List<InventarioPerguntaResposta> perguntaRespostas) {
        User me = userService.getUserFromPrincipal(principal);
        perguntaRespostaService.save(me, perguntaRespostas);

        return perguntaRespostas;
    }

    @GetMapping(value = BASE_URL)
    public List<InventarioPerguntaResposta> getInventarioByPrincipal(Principal principal) {
        User me = userService.getUserFromPrincipal((principal));
        Inventario inventario = me.getPerfil().getInventario();

        if (inventario == null) return new ArrayList<>();

        return inventario.getPerguntasRespostas();
    }
}
