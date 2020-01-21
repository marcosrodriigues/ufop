package mr.fmr.service.impl;

import mr.fmr.model.Inventario;
import mr.fmr.model.InventarioPerguntaResposta;
import mr.fmr.model.Perfil;
import mr.fmr.model.User;
import mr.fmr.repository.InventarioPerguntaRespostaRepository;
import mr.fmr.service.InventarioPerguntaRespostaService;
import mr.fmr.service.PerfilService;
import mr.fmr.service.PerguntaService;
import mr.fmr.service.PersonalidadeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class InventarioPerguntaRespostaServiceImpl implements InventarioPerguntaRespostaService {

    @Autowired
    private InventarioPerguntaRespostaRepository repository;
    @Autowired
    private PerguntaService perguntaService;
    @Autowired
    private PerfilService perfilService;
    @Autowired
    private PersonalidadeService personalidadeService;

    @Override
    public List<InventarioPerguntaResposta> convertPergunta(List<InventarioPerguntaResposta> perguntaRespostas) {
        for (InventarioPerguntaResposta pergunta : perguntaRespostas) {
            pergunta.setPergunta(perguntaService.findOne(pergunta.getPergunta().getId()));
        }
        return perguntaRespostas;

    }

    @Override
    public List<InventarioPerguntaResposta> save(User me, List<InventarioPerguntaResposta> perguntaRespostas) {
        Perfil myProfile = me.getPerfil();
        Inventario inventario = myProfile.getInventario();

        if (inventario == null) inventario = new Inventario();

        inventario.setPerguntasRespostas(convertPergunta(perguntaRespostas));
        myProfile.setInventario(inventario);
        myProfile.setPersonalidade(personalidadeService.calcularPersonalidade(myProfile));
        myProfile = perfilService.save(myProfile);


        return myProfile.getInventario().getPerguntasRespostas();
    }
}
