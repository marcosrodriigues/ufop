package mr.fmr.payload;

import mr.fmr.CaraterRepublica;
import mr.fmr.model.*;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class ProfilePayload implements Serializable {

    private Long id;
    private String email;
    private String username;
    private String password;
    private String tipo;
    private boolean termos;

    private Perfil perfil;
    private Endereco endereco;

    private String nome;
    private String apelido;
    private Universidade universidade;
    private Republica republica;

    private CaraterRepublica carater;
    private String descricao;

    private List<Estudante> moradores = new ArrayList<>();

    public ProfilePayload() {
    }

    public ProfilePayload(Estudante estudante) {
        this.id = estudante.getId();
        this.email = estudante.getEmail();
        this.username = estudante.getUsername();
        this.password = estudante.getPassword();
        this.tipo = estudante.getTipo();
        this.termos = estudante.isTermos();

        this.perfil = estudante.getPerfil();
        this.endereco = estudante.getEndereco();

        this.nome = estudante.getNome();
        this.apelido = estudante.getApelido();
        this.universidade = estudante.getUniversidade();
        this.republica = estudante.getMoradorRepublica().getRepublica();
    }

    public ProfilePayload(Republica republica) {
        this.id = republica.getId();
        this.email = republica.getEmail();
        this.username = republica.getUsername();
        this.password = republica.getPassword();
        this.tipo = republica.getTipo();
        this.termos = republica.isTermos();

        this.perfil = republica.getPerfil();
        this.endereco = republica.getEndereco();

        this.nome = republica.getNome();

        this.carater = republica.getCarater();
        this.descricao = republica.getDescricao();

        List<Estudante> moradores = new ArrayList<>();
        for(MoradorRepublica morador : republica.getMoradores())
            moradores.add(morador.getMorador());

        this.moradores = moradores;
    }

    public ProfilePayload(User user) {
        this.id = user.getId();
        this.email = user.getEmail();
        this.username = user.getUsername();
        this.password = user.getPassword();
        this.tipo = user.getTipo();
        this.termos = user.isTermos();
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public boolean isTermos() {
        return termos;
    }

    public void setTermos(boolean termos) {
        this.termos = termos;
    }

    public Perfil getPerfil() {
        return perfil;
    }

    public void setPerfil(Perfil perfil) {
        this.perfil = perfil;
    }

    public Endereco getEndereco() {
        return endereco;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getApelido() {
        return apelido;
    }

    public void setApelido(String apelido) {
        this.apelido = apelido;
    }

    public Universidade getUniversidade() {
        return universidade;
    }

    public void setUniversidade(Universidade universidade) {
        this.universidade = universidade;
    }

    public Republica getRepublica() {
        return republica;
    }

    public void setRepublica(Republica republica) {
        this.republica = republica;
    }

    public List<Estudante> getMoradores() {
        return moradores;
    }

    public void setMoradores(List<Estudante> moradores) {
        this.moradores = moradores;
    }
}
