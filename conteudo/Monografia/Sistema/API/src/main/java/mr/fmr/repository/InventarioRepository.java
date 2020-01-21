package mr.fmr.repository;

import mr.fmr.model.Inventario;
import mr.fmr.model.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface InventarioRepository extends JpaRepository<Inventario, Long> {
    Inventario findByPerfil_User(User user);
}
