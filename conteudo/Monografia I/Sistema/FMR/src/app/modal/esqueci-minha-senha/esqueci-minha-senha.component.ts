import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-esqueci-minha-senha',
  templateUrl: './esqueci-minha-senha.component.html',
  styleUrls: ['./esqueci-minha-senha.component.css']
})
export class EsqueciMinhaSenhaComponent implements OnInit {

  constructor() { }

  ngOnInit() {
  }

  whatsapp() {
    let phone = "+5531975029572";
    let msg = "Olá, estou com dificuldade de me conectar ao FindMyRepublic. Poderia me ajudar?";
    let url = "https://api.whatsapp.com/send?phone=" + phone + "&text=" + msg;
    window.open(url, "_blank");
  }

}
