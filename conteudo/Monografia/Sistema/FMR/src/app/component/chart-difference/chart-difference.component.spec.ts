import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ChartDifferenceComponent } from './chart-difference.component';

describe('ChartDifferenceComponent', () => {
  let component: ChartDifferenceComponent;
  let fixture: ComponentFixture<ChartDifferenceComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ChartDifferenceComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ChartDifferenceComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
