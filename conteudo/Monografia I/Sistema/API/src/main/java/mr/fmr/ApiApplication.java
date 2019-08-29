package mr.fmr;

import mr.fmr.model.Questionario;
import mr.fmr.repository.QuestionarioRepository;
import mr.fmr.service.QuestionarioService;
import org.springframework.beans.factory.InitializingBean;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.security.servlet.SecurityAutoConfiguration;
import org.springframework.context.annotation.Bean;

import java.util.List;

@SpringBootApplication(exclude = SecurityAutoConfiguration.class)
public class ApiApplication {


	public static void main(String[] args) {
		SpringApplication.run(ApiApplication.class, args);
	}

	@Autowired
	public QuestionarioService service;

	@Bean
	public InitializingBean sendDatabase() {
		if (service.findAll().isEmpty())
			service.initQuestionario();

		return () -> {

		};
	}
}
