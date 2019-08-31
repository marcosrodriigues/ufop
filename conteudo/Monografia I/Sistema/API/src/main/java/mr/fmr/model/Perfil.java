package mr.fmr.model;

import com.fasterxml.jackson.annotation.JsonIgnore;

import javax.persistence.*;

@Entity
public class Perfil {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @OneToOne(mappedBy = "perfil", cascade = CascadeType.ALL)
    private User user;

    @OneToOne(cascade = CascadeType.ALL)
    @JoinColumn(name = "personalidade_id")
    private Personalidade personalidade;

    @OneToOne(cascade = CascadeType.ALL)
    @JoinColumn(name = "inventario_id")
    private Inventario inventario;


    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    @JsonIgnore
    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public Personalidade getPersonalidade() {
        return personalidade;
    }

    public void setPersonalidade(Personalidade personalidade) {
        this.personalidade = personalidade;
    }

    public Inventario getInventario() {
        return inventario;
    }

    public void setInventario(Inventario inventario) {
        this.inventario = inventario;
    }
}
