import { Component, OnInit } from '@angular/core';
import { RepublicaService } from 'src/app/service/republica.service';

@Component({
  selector: 'app-moradores',
  templateUrl: './moradores.component.html',
  styleUrls: ['./moradores.component.css']
})
export class MoradoresComponent implements OnInit {

  _aprovados : any = [ ];
  _pendentes: any = [ ];

  constructor(private _republicaService : RepublicaService) { }

  ngOnInit() {
    this.initListas();
  }

  initListas() {
    this._republicaService.findMoradores().subscribe(data => {
      this._aprovados = data;
      console.log(this._aprovados);
    });

    this._republicaService.findPendentes().subscribe(data => {
      this._pendentes = data;
      console.log(this._pendentes);
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
