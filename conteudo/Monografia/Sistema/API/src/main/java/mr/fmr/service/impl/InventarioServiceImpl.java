package mr.fmr.service.impl;

import mr.fmr.model.Inventario;
import mr.fmr.model.User;
import mr.fmr.repository.InventarioRepository;
import mr.fmr.service.InventarioService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class InventarioServiceImpl implements InventarioService {

    @Autowired
    private InventarioRepository repository;

    @Override
    public List<Inventario> findAll() {
        return repository.findAll();
    }

    @Override
    public Inventario findOne(Long id) {
        return repository.findById(id).get();
    }

    @Override
    public Inventario findByUser(User user) {
        return repository.findByPerfil_User(user);
    }

    @Override
    public List<Inventario> save(List<Inventario> inventarios) {
        return repository.saveAll(inventarios);
    }

    @Override
    public Inventario save(Inventario inventario) {
        return repository.save(inventario);
    }
}
