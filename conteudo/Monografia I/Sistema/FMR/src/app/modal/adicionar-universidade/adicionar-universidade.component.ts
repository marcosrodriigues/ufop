import { Component, OnInit } from '@angular/core';
import { UniversidadeService } from 'src/app/service/universidade.service';

@Component({
  selector: 'app-adicionar-universidade',
  templateUrl: './adicionar-universidade.component.html',
  styleUrls: ['./adicionar-universidade.component.css']
})
export class AdicionarUniversidadeComponent implements OnInit {

  universidade: any = { };

  constructor(private _servive : UniversidadeService) { }

  ngOnInit() {
  }

  save() {
    return this._servive.save(this.universidade).subscribe(data => {
      this.universidade = data;
      alert('Universidade salva!');
      window.location.href = window.location.pathname;
    });
  }

  
}
