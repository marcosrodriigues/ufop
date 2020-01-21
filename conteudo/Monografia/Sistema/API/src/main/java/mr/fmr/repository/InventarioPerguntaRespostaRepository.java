package mr.fmr.repository;

import mr.fmr.model.InventarioPerguntaResposta;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface InventarioPerguntaRespostaRepository extends JpaRepository<InventarioPerguntaResposta, Long> {
}
