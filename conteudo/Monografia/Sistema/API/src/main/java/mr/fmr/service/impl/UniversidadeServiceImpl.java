package mr.fmr.service.impl;

import mr.fmr.model.Universidade;
import mr.fmr.repository.UniversidadeReposiroty;
import mr.fmr.service.UniversidadeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UniversidadeServiceImpl implements UniversidadeService {

    @Autowired
    private UniversidadeReposiroty reposiroty;

    @Override
    public List<Universidade> findAll() {
        return reposiroty.findAll();
    }

    @Override
    public Universidade save(Universidade universidade) {
        return reposiroty.save(universidade);
    }
}
