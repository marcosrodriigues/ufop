package mr.fmr.repository;

import mr.fmr.model.Perfil;
import mr.fmr.model.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface PerfilRepository extends JpaRepository<Perfil, Long> {

    Perfil findByUser(User user);
}
