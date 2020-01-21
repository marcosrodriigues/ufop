import { Component, OnInit, OnChanges } from '@angular/core';
import { AdminService } from '../../service/admin.service';

@Component({
  selector: 'app-admin-lista-estudante-sem-republica',
  templateUrl: './admin-lista-estudante-sem-republica.component.html',
  styleUrls: ['./admin-lista-estudante-sem-republica.component.css']
})
export class AdminListaEstudanteSemRepublicaComponent implements OnInit, OnChanges {

  estudantes: any = [];
  estudante: any = {};
  constructor(private _admin : AdminService) { }

  recomendacao: any = []

  ngOnInit() {
    this._admin.initEstudantes().subscribe(data => {
      this.estudantes = data;
    })

    this._admin.recomendar(this.estudante.id).subscribe(data => {
      this.recomendacao = data;
    });
  }

  ngOnChanges() {
    
  }

  recomenda(est) {
    this._admin.recomendar(est.id).subscribe(data => {
      this.recomendacao = data;
    });
  }

  sumPersonalidade(person) {
    return (person.abertura + person.concordancia + person.consciencia + person.extroversao + person.neuroticismo);
  }

  calculaPorcentagem(rep, me) {
    me = me.personalidade;
    if (rep.distanciaGeral >= this.sumPersonalidade(me))
      return Math.round((1 - this.sumPersonalidade(me) / rep.distanciaGeral) * 100);

    return Math.round((1 - rep.distanciaGeral / this.sumPersonalidade(me)) * 100);
  }

}
