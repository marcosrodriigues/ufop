package mr.fmr.service.impl;

import mr.fmr.model.User;
import mr.fmr.repository.UserRepository;
import mr.fmr.service.EstudanteService;
import mr.fmr.service.RepublicaService;
import mr.fmr.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
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

    @Autowired
    private EstudanteService estudanteService;

    @Autowired
    private RepublicaService republicaService;

    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        User user = repository.findByUsernameOrEmail(username, username);
        if (user == null) {
            throw new UsernameNotFoundException("Invalid username or password.");
        }
        return new org.springframework.security.core.userdetails.User(user.getUsername(), user.getPassword(), getAuthority(user));
    }

    private List<SimpleGrantedAuthority> getAuthority(User user) {
        return Arrays.asList(new SimpleGrantedAuthority(user.getTipo()));
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
        if (repository.findByEmail(user.getEmail()) != null) {
            return user;
        }

        if (user.getUsername() == null || user.getUsername().isEmpty()) {
            String username = user.getEmail().split("@")[0];
            User userAux = repository.findByUsername(username);
            if (userAux == null)
                user.setUsername(username);
        }

        user.setPassword(passwordEncoder.encode(user.getPassword()));


        if (user.getTipo().equalsIgnoreCase("ESTUDANTE")) {
            return estudanteService.save(user);
        } else if (user.getTipo().equalsIgnoreCase("REPUBLICA")) {
            return republicaService.save(user);
        }
        return null;
    }
}
