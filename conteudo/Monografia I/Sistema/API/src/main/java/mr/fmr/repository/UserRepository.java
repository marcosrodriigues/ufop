package mr.fmr.repository;

import mr.fmr.model.User;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface UserRepository extends CrudRepository<User, Long> {
    User findByUsername(String username);
    User findByUsernameOrEmail(String username, String email);
    User findByEmail(String email);
}
