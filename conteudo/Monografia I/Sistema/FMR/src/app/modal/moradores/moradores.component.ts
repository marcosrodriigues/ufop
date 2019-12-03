import { Component, OnInit } from '@angular/core';
import { RepublicaService } from 'src/app/service/republica.service';
import { PersonalidadeService } from 'src/app/service/personalidade.service';

@Component({
  selector: 'app-moradores',
  templateUrl: './moradores.component.html',
  styleUrls: ['./moradores.component.css']
})
export class MoradoresComponent implements OnInit {

  _aprovados : any = [ ];
  _pendentes: any = [ ];

  constructor(private _republicaService : RepublicaService, private _personalidadeService : PersonalidadeService) { }

  ngOnInit() {
    this.initListas();
  }

  initListas() {
    this._republicaService.findMoradores().subscribe(data => {
      this._aprovados = data;
      
      for (let aprov of this._aprovados) {
        if (aprov.perfil.personalidade != null) {
          aprov.perfil.personalidade = this._personalidadeService.setPercentage(aprov.perfil.personalidade);
        }
      }
    });

    this._republicaService.findPendentes().subscribe(data => {
      this._pendentes = data;
      
    });
  }

  aprovar(morador: any) {
    this._republicaService.aprovar(morador).subscribe(data => {
      this.initListas();
    })
  }

  recusar(morador: any) {

    this._republicaService.recusar(morador).subscribe(data => {
      this.initListas();

    })
  }

}
