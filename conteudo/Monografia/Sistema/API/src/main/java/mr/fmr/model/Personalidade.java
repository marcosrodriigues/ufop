package mr.fmr.model;

import com.fasterxml.jackson.annotation.JsonIgnore;

import javax.persistence.*;

@Entity
public class Personalidade {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;


    @OneToOne(mappedBy = "personalidade")
    private Perfil perfil;

    private int abertura;
    private int consciencia;
    private int neuroticismo;
    private int extroversao;
    private int concordancia;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    @JsonIgnore
    public Perfil getPerfil() {
        return perfil;
    }

    public void setPerfil(Perfil perfil) {
        this.perfil = perfil;
    }

    public int getAbertura() {
        return abertura;
    }

    public void setAbertura(int abertura) {
        this.abertura = abertura;
    }

    public int getConsciencia() {
        return consciencia;
    }

    public void setConsciencia(int consciencia) {
        this.consciencia = consciencia;
    }

    public int getNeuroticismo() {
        return neuroticismo;
    }

    public void setNeuroticismo(int neuroticismo) {
        this.neuroticismo = neuroticismo;
    }

    public int getExtroversao() {
        return extroversao;
    }

    public void setExtroversao(int extroversao) {
        this.extroversao = extroversao;
    }

    public int getConcordancia() {
        return concordancia;
    }

    public void setConcordancia(int concordancia) {
        this.concordancia = concordancia;
    }
}
