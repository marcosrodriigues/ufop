package mr.fmr.service;

import java.util.List;

public interface EnderecoService {

    List<String> getCityWhereHasRepublic(String uf);
    List<String> getUfWhereHasRepublic();
}
