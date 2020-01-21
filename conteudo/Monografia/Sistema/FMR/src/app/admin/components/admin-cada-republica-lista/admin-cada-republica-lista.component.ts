import { Component, OnInit, Input, OnChanges } from '@angular/core';
import { AdminService } from '../../service/admin.service';

@Component({
  selector: 'app-admin-cada-republica-lista',
  templateUrl: './admin-cada-republica-lista.component.html',
  styleUrls: ['./admin-cada-republica-lista.component.css']
})
export class AdminCadaRepublicaListaComponent implements OnInit, OnChanges {

  @Input("republica") rep : any = {}
  estudante : any = {};

  constructor(private _admin : AdminService) { }

  ngOnInit() {
  }

  ngOnChanges() {
  }

  aprovar(morador) {
    this._admin.aprovar(morador.id).subscribe(data => {
      this.rep = data;
    })
  }

  remove(morador) {
    this._admin.remove(morador.id).subscribe(data => {
      this.rep = data;
    })
  }

  updatePersonalidade() {
    this._admin.updatePersonalidade(this.rep.id).subscribe(data => {
      this.rep = data;
    })
  }

  recomenda(morador) {
    this.estudante = morador;
  }
}
