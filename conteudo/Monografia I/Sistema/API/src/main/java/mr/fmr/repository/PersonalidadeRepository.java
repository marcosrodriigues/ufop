package mr.fmr.repository;

import mr.fmr.model.Personalidade;
import mr.fmr.model.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface PersonalidadeRepository extends JpaRepository<Personalidade, Long> {
    Personalidade findByPerfil_User(User user);
}
