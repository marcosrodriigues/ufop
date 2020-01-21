package mr.fmr.service.impl;

import mr.fmr.model.Estudante;
import mr.fmr.model.MoradorRepublica;
import mr.fmr.model.MoradorRepublicaId;
import mr.fmr.model.Republica;
import mr.fmr.repository.MoradorRepublicaRepository;
import mr.fmr.service.MoradorRepublicaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class MoradorRepublicaServiceImpl implements MoradorRepublicaService {

    @Autowired
    private MoradorRepublicaRepository repository;

    @Override
    public MoradorRepublica vincular(Estudante estudante, Republica republica) {
        MoradorRepublica moradorRepublica = new MoradorRepublica(estudante, republica);
        return repository.save(moradorRepublica);
    }

    @Override
    public MoradorRepublica aprovar(Estudante estudante, Republica republica) {
        MoradorRepublica moradorRepublica = repository.findById(new MoradorRepublicaId(estudante.getId(), republica.getId())).get();

        if (moradorRepublica != null) {
            moradorRepublica.setAprovado(true);
            return repository.save(moradorRepublica);
        }

        return null;
    }

    @Override
    public void recusar(Estudante estudante, Republica republica) {
        MoradorRepublica moradorRepublica = repository.findById(new MoradorRepublicaId(estudante.getId(), republica.getId())).get();

        if (moradorRepublica != null) {
            repository.delete(moradorRepublica);
            return;
        }

        return;
    }
}
