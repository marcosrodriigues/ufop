import { Component, OnInit, Input, OnChanges } from '@angular/core';
import { AdminService } from '../../service/admin.service';

@Component({
  selector: 'app-recomendar',
  templateUrl: './recomendar.component.html',
  styleUrls: ['./recomendar.component.css']
})
export class RecomendarComponent implements OnInit, OnChanges {

  @Input("estudante") estudante : any = {nome : '', apelido : ''};
  recomendacao : any = [];
  constructor(private _admin : AdminService) { }

  ngOnInit() {
    
  }

  ngOnChanges() {
    console.log(this.estudante);
    this.recomendacao = [];
    if(this.estudante.id != undefined)
      this._admin.recomendar(this.estudante.id).subscribe(data => {
        this.recomendacao = data;
      })
  }

  sumPersonalidade(person) {
    return (person.abertura + person.concordancia + person.consciencia + person.extroversao + person.neuroticismo);
  }

  calculaPorcentagem(rep, me) {
    if (me.perfil != undefined) {
      me = me.perfil.personalidade;
      if (me == null) return;
      if (rep.distanciaGeral >= this.sumPersonalidade(me))
        return Math.round((1 - this.sumPersonalidade(me) / rep.distanciaGeral) * 100);
  
      return Math.round((1 - rep.distanciaGeral / this.sumPersonalidade(me)) * 100);
    }
    
  }

}
