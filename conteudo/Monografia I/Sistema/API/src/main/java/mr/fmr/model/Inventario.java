package mr.fmr.model;

import javax.persistence.*;
import java.util.List;

@Entity
public class Inventario {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @OneToOne
    private Perfil perfil;

    @OneToMany(cascade = CascadeType.PERSIST)
    private List<InventarioPerguntaResposta> perguntasRespostas;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Perfil getPerfil() {
        return perfil;
    }

    public void setPerfil(Perfil perfil) {
        this.perfil = perfil;
    }

    public List<InventarioPerguntaResposta> getPerguntasRespostas() {
        return perguntasRespostas;
    }

    public void setPerguntasRespostas(List<InventarioPerguntaResposta> perguntasRespostas) {
        this.perguntasRespostas = perguntasRespostas;
    }
}
