package mr.fmr.service.impl;

import mr.fmr.model.*;
import mr.fmr.repository.RepublicaRepository;
import mr.fmr.service.EstudanteService;
import mr.fmr.service.RepublicaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service("republicaService")
public class RepublicaServiceImpl implements RepublicaService {

    @Autowired
    private RepublicaRepository repository;
    @Autowired
    private EstudanteService estudanteService;

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

    @Override
    public List<Estudante> findMoradores(Republica republica) {
        return getApprovedMoradores(republica);
    }

    @Override
    public List<Estudante> findPendentes(Republica republica) {
        List<Estudante> pendentes = new ArrayList<>();

        for (MoradorRepublica estudante : republica.getMoradores())
            if (!estudante.isAprovado()) pendentes.add(estudante.getMorador());

        return pendentes;
    }

    @Override
    public Republica createPersonality(Republica republica) {
        List<Estudante> moradores = findMoradores(republica);

        Personalidade personality = new Personalidade();

        moradores.forEach(m -> {
            personality.setAbertura(personality.getAbertura() + m.getPerfil().getPersonalidade().getAbertura());
            personality.setNeuroticismo(personality.getNeuroticismo() + m.getPerfil().getPersonalidade().getNeuroticismo());
            personality.setConsciencia(personality.getNeuroticismo() + m.getPerfil().getPersonalidade().getNeuroticismo());
            personality.setConcordancia(personality.getConsciencia() + m.getPerfil().getPersonalidade().getConcordancia());
            personality.setExtroversao(personality.getExtroversao() + m.getPerfil().getPersonalidade().getExtroversao());
        });

        personality.setAbertura(personality.getAbertura() / moradores.size());
        personality.setNeuroticismo(personality.getNeuroticismo() / moradores.size());
        personality.setConsciencia(personality.getConsciencia() / moradores.size());
        personality.setConcordancia(personality.getConcordancia() / moradores.size());
        personality.setExtroversao(personality.getExtroversao() / moradores.size());

        Perfil perfil = new Perfil();
        perfil.setPersonalidade(personality);

        republica.setPerfil(perfil);

        return save(republica);
    }

    //private methods
    private List<Estudante> getApprovedMoradores(Republica republica) {
        if (republica.getMoradores().isEmpty()) return null;

        List<Estudante> moradores = new ArrayList<>();

        for (MoradorRepublica mr : republica.getMoradores())
            if (mr.isAprovado()) moradores.add(mr.getMorador());

        return moradores;
    }
}
