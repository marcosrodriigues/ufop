package mr.fmr.repository;

import mr.fmr.model.MoradorRepublica;
import mr.fmr.model.MoradorRepublicaId;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface MoradorRepublicaRepository extends JpaRepository<MoradorRepublica, MoradorRepublicaId> {
}
