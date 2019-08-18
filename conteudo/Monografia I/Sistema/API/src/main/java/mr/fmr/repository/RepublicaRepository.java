package mr.fmr.repository;

import mr.fmr.model.Republica;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface RepublicaRepository extends JpaRepository<Republica, Long> {
}
