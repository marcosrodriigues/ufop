package mr.fmr.service.impl;

import mr.fmr.repository.EnderecoRepository;
import mr.fmr.service.EnderecoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class EnderecoServiceImpl implements EnderecoService {

    @Autowired
    private EnderecoRepository repository;

    @Override
    public List<String> getCityWhereHasRepublic(String uf) {
        return repository.findCityWhereHasRepublic(uf);
    }

    @Override
    public List<String> getUfWhereHasRepublic() {
        return repository.findUfWhereHasRepublic();
    }
}
