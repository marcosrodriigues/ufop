package mr.fmr.controller;

import mr.fmr.model.Inventario;
import mr.fmr.model.InventarioPerguntaResposta;
import mr.fmr.model.Perfil;
import mr.fmr.model.User;
import mr.fmr.service.InventarioPerguntaRespostaService;
import mr.fmr.service.InventarioService;
import mr.fmr.service.PerfilService;
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
    private InventarioService service;
    @Autowired
    private InventarioPerguntaRespostaService perguntaRespostaService;
    @Autowired
    private UserService userService;
    @Autowired
    private PerfilService perfilService;

    @PostMapping(value = BASE_URL)
    public Inventario saveAll(Principal principal, @RequestBody  List<InventarioPerguntaResposta> perguntaRespostas) {
        User me = userService.getUserFromPrincipal(principal);
        Perfil myProfile = perfilService.findByUser(me);

        if (myProfile == null) {
            myProfile = new Perfil();
            myProfile.setUser(me);
            myProfile = perfilService.save(myProfile);
        }

        Inventario inventario = service.findByUser(me);
        if (inventario == null) {
            inventario = new Inventario();
            inventario.setPerfil(myProfile);
        }

        //List<InventarioPerguntaResposta> respostas =

        inventario.setPerguntasRespostas(
            perguntaRespostaService.save(
                    perguntaRespostaService.convertPergunta(perguntaRespostas)
            )
        );

        return service.save(inventario);
    }

    @GetMapping(value = BASE_URL)
    public List<InventarioPerguntaResposta> getInventarioByPrincipal(Principal principal) {
        User me = userService.getUserFromPrincipal((principal));
        Inventario inventario = service.findByUser(me);

        if (inventario == null) return new ArrayList<InventarioPerguntaResposta>();

        return inventario.getPerguntasRespostas();
    }
}
