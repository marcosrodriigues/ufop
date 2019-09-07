package mr.fmr.model;

import javax.persistence.Column;
import javax.persistence.Embeddable;
import java.io.Serializable;
import java.util.Objects;

@Embeddable
public class MoradorRepublicaId implements Serializable {

    @Column(name = "estudante_id")
    private Long estudante_id;
    @Column(name = "republica_id")
    private Long republica_id;

    private MoradorRepublicaId() {

    }

    public MoradorRepublicaId(Long estudante, Long republica) {
        this.estudante_id = estudante;
        this.republica_id = republica;
    }

    public Long getEstudante_id() {
        return estudante_id;
    }

    public void setEstudante_id(Long estudante_id) {
        this.estudante_id = estudante_id;
    }

    public Long getRepublica_id() {
        return republica_id;
    }

    public void setRepublica_id(Long republica_id) {
        this.republica_id = republica_id;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof MoradorRepublicaId)) return false;
        MoradorRepublicaId that = (MoradorRepublicaId) o;
        return Objects.equals(getEstudante_id(), that.getEstudante_id()) &&
                Objects.equals(getRepublica_id(), that.getRepublica_id());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getEstudante_id(), getRepublica_id());
    }
}

