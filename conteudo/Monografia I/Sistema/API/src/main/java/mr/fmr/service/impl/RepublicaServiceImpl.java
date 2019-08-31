package mr.fmr.service.impl;

import mr.fmr.model.Republica;
import mr.fmr.model.User;
import mr.fmr.repository.RepublicaRepository;
import mr.fmr.repository.UserRepository;
import mr.fmr.service.RepublicaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service("republicaService")
public class RepublicaServiceImpl implements RepublicaService {

    @Autowired
    private RepublicaRepository repository;

    @Autowired
    private UserRepository userRepository;

    @Override
    public Republica save(User user) {
        if (user.getId() == null) {
            Republica rep = new Republica(user);
            return repository.save(rep);
        }

        return repository.save((Republica) user);
    }

    @Override
    public List<Republica> findAll() {
        return repository.findAll();
    }

    @Override
    public Republica findOne(long id) {
        Republica rep = (Republica) userRepository.findById(id).get();
        return rep;
    }


    @Override
    public void delete(long id) {
        repository.deleteById(id);
    }
}
