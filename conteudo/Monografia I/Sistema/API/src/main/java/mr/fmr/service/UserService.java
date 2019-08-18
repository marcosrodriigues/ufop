package mr.fmr.service;

import mr.fmr.model.User;

import java.util.List;

public interface UserService {

    User save(User user);
    List<User> findAll();
    User findOne(long id);
    void delete(long id);

}
