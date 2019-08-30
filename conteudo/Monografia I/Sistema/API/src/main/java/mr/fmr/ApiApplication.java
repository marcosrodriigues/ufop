package mr.fmr;

import mr.fmr.service.PerguntaService;
import org.springframework.beans.factory.InitializingBean;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.security.servlet.SecurityAutoConfiguration;
import org.springframework.context.annotation.Bean;

@SpringBootApplication(exclude = SecurityAutoConfiguration.class)
public class ApiApplication {


	public static void main(String[] args) {
		SpringApplication.run(ApiApplication.class, args);
	}

	@Autowired
	public PerguntaService service;

	@Bean
	public InitializingBean sendDatabase() {
		if (service.findAll().isEmpty())
			service.initQuestionario();

		return () -> {

		};
	}
}
