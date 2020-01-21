package mr.fmr.service;

import mr.fmr.model.Inventario;
import mr.fmr.model.User;

import java.util.List;

public interface InventarioService {

    List<Inventario> findAll();
    Inventario findOne(Long id);
    Inventario findByUser(User user);
    List<Inventario> save(List<Inventario> inventarios);
    Inventario save(Inventario inventario);
    //List<Inventario> convertPerguntas(List<Inventario> inventarios);
}
