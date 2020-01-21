package mr.fmr.repository;

import mr.fmr.model.Endereco;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface EnderecoRepository extends JpaRepository<Endereco, Long> {

    @Query("SELECT DISTINCT u.endereco.cidade FROM User AS u WHERE u.tipo = 'REPUBLICA' AND u.endereco.uf = ?1")
    List<String> findCityWhereHasRepublic(String uf);

    @Query("SELECT DISTINCT u.endereco.uf FROM User AS u WHERE u.tipo = 'REPUBLICA'")
    List<String> findUfWhereHasRepublic();
}
