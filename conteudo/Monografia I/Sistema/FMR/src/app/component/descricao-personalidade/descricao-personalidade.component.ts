import { Component, OnInit, Input } from '@angular/core';
import { PercentPipe } from '@angular/common';

@Component({
  selector: 'app-descricao-personalidade',
  templateUrl: './descricao-personalidade.component.html',
  styleUrls: ['./descricao-personalidade.component.css']
})
export class DescricaoPersonalidadeComponent implements OnInit {

  @Input("personality") personalidade: any = {};

  percent : any = {};

  constructor() { }

  ngOnChanges() {
    this.setPercentage();
  }

  ngOnInit() {
    this.setPercentage();
  }

  setPercentage() {
    this.percent.abertura = this.round(this.personalidade.abertura / 50 * 100, 2) + "%";
    this.percent.concordancia = this.round(this.personalidade.concordancia / 45 * 100, 2) + "%";
    this.percent.consciencia = this.round(this.personalidade.consciencia / 45 * 100, 2) + "%";
    this.percent.extroversao = this.round(this.personalidade.extroversao / 40 * 100, 2) + "%";
    this.percent.neuroticismo = this.round(this.personalidade.neuroticismo / 40 * 100, 2) + "%";
  }

  private round(value, exp) {
    return value.toFixed(exp);
  }


}
