package mr.fmr;

import mr.fmr.pojo.FileStorageProperties;
import mr.fmr.service.PerguntaService;
import mr.fmr.service.StorageService;
import org.springframework.beans.factory.InitializingBean;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.security.servlet.SecurityAutoConfiguration;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.annotation.Bean;

@SpringBootApplication(exclude = SecurityAutoConfiguration.class)
@EnableConfigurationProperties(
		FileStorageProperties.class
)
public class ApiApplication implements CommandLineRunner {

	@Autowired
	private PerguntaService perguntaService;
	@Autowired
	private StorageService storageService;


	public static void main(String[] args) {
		SpringApplication.run(ApiApplication.class, args);
	}

	@Override
	public void run(String... args) throws Exception {
		//storageService.deleteAll();;
		//storageService.init();
	}

	@Bean
	public InitializingBean sendDatabase() {
		if (perguntaService.findAll().isEmpty())
			perguntaService.initQuestionario();

		return () -> {

		};
	}
}
