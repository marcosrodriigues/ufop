package mr.fmr.service.impl;

import mr.fmr.model.Republica;
import mr.fmr.model.User;
import mr.fmr.repository.RepublicaRepository;
import mr.fmr.service.RepublicaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.List;

@Service("republicaService")
public class RepublicaServiceImpl implements RepublicaService {

    @Autowired
    private RepublicaRepository repository;

    @Autowired
    private PasswordEncoder passwordEncoder;

    @Override
    public Republica save(User user) {
        if (user.getId() == null) {
            Republica rep = new Republica(user);
            return repository.save(rep);
        }

        Republica other = repository.findById(user.getId()).get();

        if (!other.getPassword().equals(user.getPassword()))
            user.setPassword(passwordEncoder.encode(user.getPassword()));

        return repository.save((Republica) user);
    }

    @Override
    public List<Republica> findAll() {
        return repository.findAll();
    }

    @Override
    public Republica findOne(long id) {
        Republica rep = repository.findById(id).get();
        return rep;
    }

    @Override
    public void delete(long id) {
        repository.deleteById(id);
    }

    @Override
    public List<Republica> findByUf(String uf) {
        return repository.findByEndereco_Uf(uf);
    }

    @Override
    public List<Republica> findByUfAndCity(String uf, String city) {
        return repository.findByEndereco_UfAndEndereco_Cidade(uf, city);
    }

}
