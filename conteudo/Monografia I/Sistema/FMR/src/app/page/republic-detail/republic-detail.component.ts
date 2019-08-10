import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import * as CanvasJS from '../../../assets/js/canvasjs.min';

@Component({
  selector: 'app-republic-detail',
  templateUrl: './republic-detail.component.html',
  styleUrls: ['./republic-detail.component.css']
})
export class RepublicDetailComponent implements OnInit {

  rep = "República Maternidade";
  fullImagePath = '/content/republica/maternidade.png';
  cidade = '';

  data = [
    { y: 52, name: "Abertura para o novo" },
    { y: 68, name: "Realização" },
    { y: 40, name: "Extroversão" },
    { y: 35, name: "Socialização" },
    { y: 75, name: "Neuroticismo" },
  ];

  constructor(private router: ActivatedRoute) { 
    this.router.paramMap.subscribe(params => {
      this.cidade = params.get("id");
    })
  }

  ngOnInit() {
      this.initializeChart('chart');
  }

  initializeChart(id) {
    let chart = new CanvasJS.Chart(id, {
      theme: "light2",
      animationEnabled: true,
      exportEnabled: true,
      title:{
        text: "Personalidade"
      },
      data: [{
        type: "pie",
        showInLegend: true,
        toolTipContent: "<b>{name}</b>: {y} (#percent%)",
        indexLabel: "{name} - #percent%",
        dataPoints: this.data,
      }]
    });
    chart.render();
  }

}
