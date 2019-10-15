import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import * as CanvasJS from '../../../assets/js/canvasjs.min';
import { RepublicaService } from 'src/app/service/republica.service';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-search',
  templateUrl: './search.component.html',
  styleUrls: ['./search.component.css']
})
export class SearchComponent implements OnInit {

  cidade = '';
  reps: any = [];
  me : any = {};

  data: any = [[
    { y: 52, label: "Abertura para o novo" },
    { y: 68, label: "Concordancia" },
    { y: 40, label: "Consciencia" },
    { y: 35, label: "Extroversao" },
    { y: 75, label: "Neuroticismo" }
  ]];

  myData = [
    { y: 0.1, label: "Abertura para o novo" },
    { y: 0.1, label: "Concordancia" },
    { y: 0.1, label: "Consciencia" },
    { y: 0.1, label: "Extroversao" },
    { y: 0.1, label: "Neuroticismo" },
  ]

  constructor(private router: ActivatedRoute, 
              private _repService : RepublicaService,
              private _userService : UserService) { 
    this.router.queryParams.subscribe(params => {
      this.cidade = params['q'];
    })
  }

  ngOnInit() {
      this.loadMe();
      this.loadReps();
  }

  loadMe() {
    this._userService.me().subscribe((data: any) => {
      this.me = data.perfil.personalidade;

      this.myData[0].y = this.me.abertura / 50 * 100;
      this.myData[1].y = this.me.concordancia / 45 * 100;
      this.myData[2].y = this.me.consciencia / 45 * 100;
      this.myData[3].y = this.me.extroversao / 40 * 100;
      this.myData[4].y = this.me.neuroticismo / 40*100;
    })
  }

  loadReps() {
    this._repService.findByCity(this.cidade).subscribe(data => {
      this.reps = data;

      this.data = [];
      let newChart: any = [];
      for(let i = 0; i < this.reps.length; i++) {
          newChart = [
          { y: 0.1, label: "Abertura para o novo" },
          { y: 0.1, label: "Concordancia" },
          { y: 0.1, label: "Consciencia" },
          { y: 0.1, label: "Extroversao" },
          { y: 0.1, label: "Neuroticismo" }
        ];

        newChart[0].y = this.reps[i].personalidade.abertura / 50 * 100;
        newChart[1].y = this.reps[i].personalidade.concordancia / 45 * 100;
        newChart[2].y = this.reps[i].personalidade.consciencia / 45 * 100;
        newChart[3].y = this.reps[i].personalidade.extroversao / 40 * 100;
        newChart[4].y = this.reps[i].personalidade.neuroticismo / 40 * 100;

        this.data.push(newChart);
      }

      this.initCharts();
    }, err => {
      alert(err.error.message);
    });
  }

  initCharts() {
    setTimeout(() => {
      for(let i = 0; i < this.reps.length; i++)
        this.initializeChart("chart_" + i, i);
    }, 1000);
  }

  initializeChart(id, i) {
    let chart = new CanvasJS.Chart(id, {
      theme: "light2",
      animationEnabled: true,
      exportEnabled: true,
      title:{
        text: "República vs Estudante"
      },
      axisY: {
        title: "Pontuação"
      },
      toolTip: {
        shared: true
      },
      legend: {
        cursor: "pointer"
      },
      data: [{
        type: "column",
        name: "Minha personalidade",
        legendText: "Minha personalidade",
        showInLegend: true,
        dataPoints: this.myData,
      },{
        type: "column",
        name: "República",
        legendText: "Personalidade da República",
        showInLegend: true,
        dataPoints: this.data[i],
      },]
    });
    chart.render();
  }

  abs(num) {
    return (num < 0) ? num * -1 : num;
  }

  sumPersonalidade(person) {
    return (person.abertura + person.concordancia + person.consciencia + person.extroversao + person.neuroticismo);
  }

  calculaPorcentagem(rep, me) {
    if (rep.distanciaGeral >= this.sumPersonalidade(me))
      return Math.round((1 - this.sumPersonalidade(me) / rep.distanciaGeral) * 100);

    return Math.round((1 - rep.distanciaGeral / this.sumPersonalidade(me)) * 100);
  }
}
