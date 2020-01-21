package mr.fmr.repository;

import mr.fmr.model.Universidade;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface UniversidadeReposiroty extends JpaRepository<Universidade, Long> {
}
