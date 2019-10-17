import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-table-compare',
  templateUrl: './table-compare.component.html',
  styleUrls: ['./table-compare.component.css']
})
export class TableCompareComponent implements OnInit {

  @Input("me") me : any = {};
  @Input("other") other: any = {};

  percentMe: any = {};
  percentOther: any = {};

  constructor() { }

  ngOnInit() {
    this.configure();
  }

  ngOnChanges() {
    this.configure();
  }

  configure() {
    this.percentMe.abertura = this.round(this.me.abertura / 50 * 100, 2);
    this.percentOther.abertura = this.round(this.other.abertura / 50 * 100, 2);

    this.percentMe.concordancia = this.round(this.me.concordancia / 45 * 100, 2);
    this.percentOther.concordancia = this.round(this.other.concordancia / 45 * 100, 2);

    this.percentMe.consciencia = this.round(this.me.consciencia / 45 * 100, 2);
    this.percentOther.consciencia = this.round(this.other.consciencia / 45 * 100, 2);

    this.percentMe.extroversao = this.round(this.me.extroversao / 40 * 100, 2);
    this.percentOther.extroversao = this.round(this.other.extroversao / 45 * 100, 2);

    this.percentMe.neuroticismo = this.round(this.me.neuroticismo / 40 * 100, 2);
    this.percentOther.neuroticismo = this.round(this.other.neuroticismo / 45 * 100, 2);
  }

  abs(num) {
    return this.round((num < 0) ? num * -1 : num, 2);
  }

  round(value, exp) {
    return parseFloat(value.toFixed(exp));
  }

  sumPersonalidade(person) {
    return (person.abertura + person.concordancia + person.consciencia + person.extroversao + person.neuroticismo);
  }
}
