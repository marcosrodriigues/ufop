package mr.fmr.repository;

import mr.fmr.model.Republica;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface RepublicaRepository extends JpaRepository<Republica, Long> {

    List<Republica> findByEndereco_Uf(String uf);
    List<Republica> findByEndereco_UfAndEndereco_Cidade(String uf, String cidade);
    List<Republica> findByEndereco_Cidade(String cidade);
}
