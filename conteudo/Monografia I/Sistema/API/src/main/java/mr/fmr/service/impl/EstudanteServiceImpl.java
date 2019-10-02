package mr.fmr.service.impl;

import mr.fmr.model.Estudante;
import mr.fmr.model.User;
import mr.fmr.repository.EstudanteRepository;
import mr.fmr.service.EstudanteService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.List;

@Service("estudanteService")
public class EstudanteServiceImpl implements EstudanteService {


    @Autowired
    private EstudanteRepository repository;
    @Autowired
    private PasswordEncoder passwordEncoder;

    @Override
    public Estudante save(User user) {
        if (user.getId() == null) {
            Estudante estudante = new Estudante(user);
            return repository.save(estudante);
        }

        Estudante other = repository.findById(user.getId()).get();

        if (!other.getPassword().equals(user.getPassword()))
            user.setPassword(passwordEncoder.encode(user.getPassword()));

        return repository.save((Estudante) user);
    }

    @Override
    public List<Estudante> findAll() {
        return repository.findAll();
    }

    @Override
    public Estudante findOne(long id) {return repository.findById(id).get(); }

    @Override
    public void delete(long id) {
        repository.deleteById(id);
    }
}
