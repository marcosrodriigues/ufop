package mr.fmr.service.impl;

import mr.fmr.model.User;
import mr.fmr.repository.UserRepository;
import mr.fmr.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.List;

@Service("userService")
public class UserServiceImpl implements UserDetailsService, UserService {

    @Autowired
    private UserRepository repository;

    @Autowired
    private PasswordEncoder passwordEncoder;

    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        User user = repository.findByUsername(username);
        if (user == null) {
            throw new UsernameNotFoundException("Invalid username or password.");
        }
        return new org.springframework.security.core.userdetails.User(user.getUsername(), user.getPassword(), getAuthority());
    }

    private List<SimpleGrantedAuthority> getAuthority() {
        return Arrays.asList(new SimpleGrantedAuthority("ROLE_ADMIN"));
    }

    @Override
    public List<User> findAll() {
        List<User> list = (List<User>) repository.findAll();
        return list;
    }

    @Override
    public User findOne(long id) {
        return repository.findById(id).get();
    }

    @Override
    public void delete(long id) {
        repository.deleteById(id);
    }

    @Override
    public User save(User user) {

        if (user.getUsername() == null || user.getUsername().isEmpty()) user.setUsername(user.getEmail().split("@")[0]);
        user.setPassword(passwordEncoder.encode(user.getPassword()));

        return repository.save(user);
    }
}
