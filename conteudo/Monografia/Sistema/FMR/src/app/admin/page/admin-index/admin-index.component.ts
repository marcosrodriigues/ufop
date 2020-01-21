import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-admin-index',
  templateUrl: './admin-index.component.html',
  styleUrls: ['./admin-index.component.css']
})
export class AdminIndexComponent implements OnInit {

  showRepublicas: boolean = true;
  showEstudantes: boolean = true;
  constructor() { }

  ngOnInit() {
  }

  toggleRepublica() {
    this.showRepublicas = !this.showRepublicas;
  }

  toggleEstudante() {
    this.showEstudantes = !this.showEstudantes;
  }
}
